#include "weblegends.h"
#include "modules/Filesystem.h"

command_result WebLegends::export_all(color_ostream & out, const std::string & folder)
{
    if (!is_world_loaded())
    {
        out.printerr("no world is loaded\n");
        return CR_FAILURE;
    }

    if (Filesystem::exists(folder))
    {
        out.printerr("already exists: %s\n", folder.c_str());
        return CR_FAILURE;
    }

    if (!Filesystem::mkdir(folder))
    {
        out.printerr("failed to create: %s\n", folder.c_str());
        return CR_FAILURE;
    }

    std::set<std::string> exported;
    return export_recursive(out, exported, folder, "/");
}

static void ensure_base_directories(const std::string & base_folder, const std::string & child_folders)
{
    for (size_t pos = child_folders.find('/'); pos != std::string::npos; pos = child_folders.find('/', pos + 1))
    {
        Filesystem::mkdir(base_folder + "/" + child_folders.substr(0, pos));
    }
}

command_result WebLegends::export_recursive(color_ostream & out, std::set<std::string> & exported, const std::string & folder, const std::string & url)
{
    if (url.find('?') != std::string::npos)
    {
        out.printerr("unsupported query string: %s\n", url.c_str());
        return CR_FAILURE;
    }

    if (!exported.insert(url).second)
    {
        return CR_OK;
    }

    weblegends_handler_v1_impl response;
    try
    {
        if (!request(response, url))
        {
            out.printerr("not found: %s\n", url.c_str());
            return CR_FAILURE;
        }
    }
    catch (std::exception & e)
    {
        out.printerr("failed to export: %s: %s\n", url.c_str(), e.what());
        return CR_FAILURE;
    }

    if (response.current_status_code != 200)
    {
        out.printerr("unsupported status code %d on %s\n", response.current_status_code, url.c_str());
        return CR_FAILURE;
    }

    bool is_html = response.current_headers["Content-Type"] == "text/html; charset=utf-8";

    auto body = response.body_raw.str();

    command_result cr = is_html ? export_linked_pages(out, exported, folder, url, body) : CR_OK;

    ensure_base_directories(folder, url);

    auto target_path = folder + "/" + url;
    if (target_path.at(target_path.length() - 1) == '/')
    {
        target_path += "index";
    }
    if (is_html)
    {
        target_path += ".html";
    }

    std::ofstream file_out(target_path);
    file_out << body;

    if (!file_out.good())
    {
        out.printerr("failed to write file for %s\n", url.c_str());
        cr = CR_FAILURE;
    }

    return cr;
}

static void clean_path(std::string & path)
{
    // clean up double slashes
    auto pos = path.find("//");
    while (pos != std::string::npos)
    {
        path.erase(pos, 1);
        pos = path.find("//");
    }

    // remove current directory references
    pos = path.find("/./");
    while (pos != std::string::npos)
    {
        path.erase(pos, 2);
        pos = path.find("/./");
    }

    // collapse parent directory references
    pos = path.find("/../");
    while (pos != std::string::npos)
    {
        path.erase(pos, 3);
        if (pos != 0)
        {
            auto pos1 = path.rfind('/', pos - 1);
            path.erase(pos1, pos - pos1);
        }
        pos = path.find("/../");
    }
}

command_result WebLegends::export_linked_pages(color_ostream & out, std::set<std::string> & exported, const std::string & folder, const std::string & url, std::string & body)
{
    std::string base_url = url.substr(0, url.rfind('/') + 1);

    auto pos = body.find("<base href=\"");
    if (pos != std::string::npos)
    {
        pos += strlen("<base href=\"");
        auto end_pos = body.find('"', pos);
        if (end_pos != std::string::npos)
        {
            base_url += body.substr(pos, end_pos - pos) + "/";
            clean_path(base_url);
        }
    }
    else
    {
        pos = 0;
    }

    command_result cr = CR_OK;
    while ((pos = body.find(" href=\"", pos)) != std::string::npos)
    {
        pos += strlen(" href=\"");
        auto end_pos = body.find('"', pos);
        if (end_pos != std::string::npos)
        {
            auto link_path = body.substr(pos, end_pos - pos);
            command_result cr2 = export_recursive(out, exported, folder, base_url + link_path);
            if (cr == CR_OK)
                cr = cr2;

            if (link_path.find('.') == std::string::npos)
                body.insert(end_pos, ".html");
        }
    }

    pos = 0;
    while ((pos = body.find(" src=\"", pos)) != std::string::npos)
    {
        pos += strlen(" src=\"");
        auto end_pos = body.find('"', pos);
        if (end_pos != std::string::npos)
        {
            auto link_path = body.substr(pos, end_pos - pos);
            command_result cr2 = export_recursive(out, exported, folder, base_url + link_path);
            if (cr == CR_OK)
                cr = cr2;
        }
    }

    return cr;
}
