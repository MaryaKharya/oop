@echo off

REM Путь к тестируемой программе передается через 1-й аргумент командной строки
SET Program="%~1"

REM Защита от запуска без аргумента, задающего путь к программе
if %Program%=="" (
	echo Please specify path to program
	exit /b 1
)

%Program%  "8" "15" "345" > "%TEMP%\output.txt" || goto err
fc "%TEMP%\output.txt" "empty.txt" || goto err
echo Test 1 passed

%Program% "5" "7" "-4332" > "%TEMP%\output.txt" || goto err
fc "%TEMP%\output.txt" "minus_out.txt" || goto err
echo Test 2 passed

%Program% "30" "2" "-43R2" > "%TEMP%\output.txt" || goto err
fc "%TEMP%\output.txt" "letters_out.txt" || goto err
echo Test 3 passed

%Program% "2" "10" "0" > "%TEMP%\output.txt" || goto err
fc "%TEMP%\output.txt" "zero_out.txt" || goto err
echo Test 4 passed

%Program% "16" "10" "-80000000" > "%TEMP%\output.txt" || goto err
fc "%TEMP%\output.txt" "int_min_out.txt" || goto err
echo Test 5 passed

%Program% "10" "16" "2147483648" > "%TEMP%\output.txt" && goto err
echo Test 6 passed

%Program% "16" "7" "-80000001" > "%TEMP%\output.txt" && goto err
echo Test 7 passed

%Program% "16" "10" "4AK32" > "%TEMP%\output.txt" && goto err
echo Test 8 passed

%Program% "16" "4" "a32" > "%TEMP%\output.txt" && goto err
echo Test 9 passed

%Program% "37" "4" "234" > "%TEMP%\output.txt" && goto err
echo Test 10 passed

%Program% "15" "1" "234" > "%TEMP%\output.txt" && goto err
echo Test 11 passed

%Program% "-15" "10" "234" > "%TEMP%\output.txt" && goto err
echo Test 12 passed

%Program% "15" "9r" "234" > "%TEMP%\output.txt" && goto err
echo Test 13 passed

%Program% "15" "8" "" > "%TEMP%\output.txt" && goto err
echo Test 14 passed

%Program% "15" "" "" > "%TEMP%\output.txt" && goto err
echo Test 15 passed

%Program% "" "" "" > "%TEMP%\output.txt" && goto err
echo Test 16 passed

%Program% "10" "9" > "%TEMP%\output.txt" && goto err
echo Test 17 passed

%Program% "10" > "%TEMP%\output.txt" && goto err
echo Test 18 passed

%Program% > "%TEMP%\output.txt" && goto err
echo Test 19 passed

REM Тесты прошли успешно
echo All tests passed successfuly
exit /B 0

REM Сюда будет попадать в случае ошибки
:err
echo Test failed
exit /B 1