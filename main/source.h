const char* SCRIPT = \
	"function fizzbuzz(i)\n"
	"    if i \% 15 == 0 then\n"
	"        return \"fizzbuzz\"\n"
	"    elseif i \% 3 == 0 then\n"
	"        return \"fizz\"\n"
	"    elseif i \% 5 == 0 then\n"
	"        return \"buzz\"\n"
	"    else\n"
	"        return tostring(i)\n"
	"    end\n"
	"end\n"
	"for i = 1, 100 do\n"
	"    print(fizzbuzz(i))\n"
	"end\n"
;
