@echo off

REM Путь к тестируемой программе передается через 1-й аргумент командной строки
SET Program="%~1"

REM Защита от запуска без аргумента, задающего путь к программе
if %Program%=="" (
	echo Please specify path to program
	exit /b 1
)

REM Replace non empty file
%Program% "%~dp0Fresh_fish.txt" "%TEMP%\output.txt" "sh" "nch"|| goto err
fc "%TEMP%\output.txt" "%~dp0Fresh_fish_out.txt" || goto err
echo Test 1 passed


REM Replace repeated substring
%Program% "%~dp0Numbers.txt" "%TEMP%\output.txt" "1231234" "000"|| goto err
fc "%TEMP%\output.txt" "%~dp0Numbers_out.txt" || goto err
echo Test 2 passed

REM Replace substring without looping
%Program% "%~dp0Papa.txt" "%TEMP%\output.txt" "pa" "papa"|| goto err
fc "%TEMP%\output.txt" "%~dp0Papa_out.txt" || goto err
echo Test 3 passed

REM Replace empty substring
%Program% "%~dp0Fresh_fish.txt" "%TEMP%\output.txt" "" "nch"|| goto err
fc "%TEMP%\output.txt" "%~dp0Fresh_fish.txt" || goto err
echo Test 4 passed

REM Replace substring in missing file should fail
%Program% "%~dp0Missing.txt" "%TEMP%\output.txt" "ka" "la" && goto err
echo Test 5 passed

REM Replace substring in empty file should fail
%Program% "%~dp0Empty.txt" "%TEMP%\output.txt" "olo" "you" || goto err
fc "%TEMP%\output.txt" "%~dp0Empty_out.txt" || goto err
echo Test 6 passed

REM If 1 argument is not specified, program must fail
%Program% "%~dp0Missing.txt" "%TEMP%\output.txt" "ka" && goto err
echo Test 7 passed

REM If 2 arguments is not specified, program must fail
%Program% "%~dp0Missing.txt" "%TEMP%\output.txt" && goto err
echo Test 9 passed

REM If output file is not specified, program must fail
%Program% "%~dp0Missing.txt" && goto err
echo Test 10 passed

REM If input, output files and 2 arguments are not specified, program must fail
%Program% && goto err
echo Test 11 passed

REM Тесты прошли успешно
echo All tests passed successfuly
exit /B 0

REM Сюда будет попадать в случае ошибки
:err
echo Test failed
exit /B 1