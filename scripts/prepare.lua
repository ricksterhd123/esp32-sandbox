#!/usr/bin/env lua

function escapeSourceLine(line)
    local replacements = { 
        [ [["]] ] = [[\"]], 
        [ [[\]] ] = [[\\]],
        [ [[%]] ] = [[\%]]
    }

    local escapedLine = ""
    for i = 1, #line do
        local char = line:sub(i, i)
        local escapedChar = replacements[char]
        escapedLine = escapedLine..(escapedChar or char)
    end

    return escapedLine
end

function splitByLines(source)
    local lines = {}
    for s in source:gmatch("[^\r\n]+") do
        table.insert(lines, escapeSourceLine(s))
    end
    return lines
end

function toCHeaderFile(source)
    local sourceLines = splitByLines(source)
    local cHeaderFile = 'const char* SCRIPT = \\\n'

    for i, line in ipairs(sourceLines) do
        cHeaderFile = cHeaderFile..'\t"'..line..'\\n"\n'
    end

    return cHeaderFile..';\n'
end

local scriptFile = io.open("main.lua", "r")
local cHeaderFile = io.open("main/source.h", "w")
assert(scriptFile, "Could not find main.lua")
assert(cHeaderFile, "Could not open main/source.h")

cHeaderFile:write(toCHeaderFile(scriptFile:read("*a")))
cHeaderFile:close()
scriptFile:close()

print("Finished preparing main.lua")
