#include "weblegends.h"
#include "helpers.h"

void Layout::set_title(const std::string & title)
{
    head_content << "<title>" << html_escape(title) << "</title>";
}

void Layout::set_base_path(const std::string & url)
{
    head_content << "<base href=\"" << html_escape(url) << "\">";
}

void Layout::add_header_link(const std::string & url, const std::string & label, bool current)
{
    header_nav << (current ? "<li aria-current>" : "<li>");
    if (url.empty())
        header_nav << "<a>";
    else
        header_nav << "<a href=\"" << html_escape(url) << "\">";
    header_nav << html_escape(label) << "</a></li>";
}

void Layout::add_sidebar_section(const std::string & title)
{
    if (in_sidebar_section)
    {
        sidebar_nav << "</ul></nav>";
    }
    in_sidebar_section = true;
    sidebar_nav << "<nav><h3>" << html_escape(title) << "</h3><ul>";
}

void Layout::add_sidebar_link(const std::string & url, const std::string & label)
{
    if (!in_sidebar_section)
    {
        sidebar_nav << "<nav><ul>";
        in_sidebar_section = true;
    }
    sidebar_nav << "<li><a href=\"" << html_escape(url) << "\">" << html_escape(label) << "</a></li>";
}

void Layout::write_to(weblegends_handler_v1& handler) const
{
    handler.headers()["Content-Type"] = "text/html; charset=utf-8";
    handler.raw_out() << "<!DOCTYPE html><html dir=\"ltr\" lang=\"en\"><head><meta charset=\"utf-8\"><link rel=\"stylesheet\" href=\"faux-wikipedia.css\">";
    handler.raw_out() << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">" << head_content.str() << "</head>";
    handler.raw_out() << "<body><header><div id=\"logo\" role=\"banner\"><a href=\"\" title=\"Visit the main page\">";
    handler.raw_out() << "<svg viewBox=\"0 0 20 29\"><path d=\"m3 1v2h-2v16h2v2h4v2h2v2h6v-4h2v-2h2v-16h-2v-2z\" fill=\"#000\"/>";
    handler.raw_out() << "<path d=\"m4 2v2h12v-2zm12 2v6h2v-6zm-12 0h-2v6h2zm2 4v2h2v-2zm6 0v2h2v-2zm-4 6v2h4v-2z\" fill=\"#fff\"/>";
    handler.raw_out() << "<path d=\"m2 10v8h2v2h4v2h2v2h4v-4h2v-2h2v-8h-2v2h-12v-2zm4 4h8v2h-8z\" fill=\"#c0c0c0\"/>";
    handler.raw_out() << "<text y=\"28\" x=\"11\">WeblegendS</text></svg></a></div><nav><ul>" << header_nav.str() << "</ul></nav></header>";
    handler.raw_out() << "<main>" << content.str() << "</main><aside>" << sidebar_nav.str();
    if (in_sidebar_section)
        handler.raw_out() << "</ul></nav>";
    handler.raw_out() << "</aside></body></html>";
}
