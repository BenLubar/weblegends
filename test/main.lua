local gui = require('gui')
local script = require('gui.script')

local args = {...}
local done_command = args[1]

function set_test_stage(stage)
    local f = io.open('test_stage.txt', 'w')
    f:write(stage)
    f:close()
end

script.start(function()
print('Running tests')

-- dismiss intro movie
while dfhack.gui.getCurFocus() == 'movieplayer' do
    gui.simulateInput(dfhack.gui.getCurViewscreen(), 'LEAVESCREEN')
    script.sleep(1, 'frames')
end

local found = false
local title_screen = dfhack.gui.getCurViewscreen()
for idx, item in ipairs(title_screen.menu_line_id) do
    if item == df.viewscreen_titlest.T_menu_line_id.Start then
        found = true
        title_screen.sel_menu_line = idx
        break
    end
end

-- generate new world
if not found then
    for idx, item in ipairs(title_screen.menu_line_id) do
        if item == df.viewscreen_titlest.T_menu_line_id.NewWorld then
            title_screen.sel_menu_line = idx
            gui.simulateInput(title_screen, 'SELECT')
            script.sleep(1, 'frames')

            local new_region = dfhack.gui.getCurViewscreen()
            while new_region.load_world_params do
                script.sleep(1, 'frames')
            end

            if #new_region.welcome_msg > 0 then
                gui.simulateInput(new_region, 'LEAVESCREEN')
                script.sleep(1, 'frames')
            end

            new_region.world_size = 0
            gui.simulateInput(new_region, 'MENU_CONFIRM')
            while #df.global.world.entities.all == 0 or new_region.simple_mode == 0 or df.global.world.worldgen_status.state ~= 10 do
                script.sleep(1, 'frames')
            end
            gui.simulateInput(new_region, 'SELECT')

            while dfhack.gui.getCurFocus() ~= 'title' do
                script.sleep(1, 'frames')
            end

            break
        end
    end
    script.sleep(100, 'frames')

    title_screen = dfhack.gui.getCurViewscreen()
    for idx, item in ipairs(title_screen.menu_line_id) do
        if item == df.viewscreen_titlest.T_menu_line_id.Start then
            title_screen.sel_menu_line = idx
            break
        end
    end
end
print('test passed: setup:generate-world')

gui.simulateInput(title_screen, 'SELECT')
script.sleep(1, 'frames')

-- try to start in legends mode
gui.simulateInput(title_screen, 'STANDARDSCROLL_UP')
script.sleep(1, 'frames')
gui.simulateInput(title_screen, 'SELECT')

while dfhack.gui.getCurFocus() ~= 'legends' do
    script.sleep(1, 'frames')
end
local legends = dfhack.gui.getCurViewscreen()
-- FIXME: this condition is wrong and assumes uninitialized memory is nonzero
while legends.cur_page ~= 0 or legends.main_cursor ~= 0 do
    script.sleep(1, 'frames')
end
print('test passed: setup:open-world')

-- don't re-run this test
set_test_stage('done')
local status = dfhack.run_command('weblegends-export', 'weblegends-tmp')

local warnings = io.open('weblegends_debug.log', 'r')
if warnings ~= nil then
    for line in warnings:lines() do
        print('WARN: ' .. dfhack.df2console(line))
    end
    warnings:close()
end

if status == CR_OK then
    print('test passed: weblegends:export')
else
    dfhack.printerr('test errored: weblegends:export: status=' .. tostring(status))
end

if done_command then
    dfhack.run_command(done_command)
end

end)
