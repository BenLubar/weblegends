local script = require('gui.script')

function set_test_stage(stage)
    local f = io.open('test_stage.txt', 'w')
    f:write(stage)
    f:close()
end

script.start(function()
print('Running tests')

-- TODO: generate and load a small world

print('Running file: main')
local status = dfhack.run_command('weblegends-export', 'weblegends-tmp')
if status == CR_OK then
    print('test passed: weblegends-export')
else
    dfhack.printerr('test errored: weblegends-export: status=' .. tostring(status))
    set_test_stage('fail')
    dfhack.run_command('die')
end

set_test_stage('done')
dfhack.run_command('die')

end)
