xc32-gcc main.c  -mprocessor=32MX250F128B 
if %errorlevel% neq 0 exit /b %errorlevel%

xc32-bin2hex a.out
if %errorlevel% neq 0 exit /b %errorlevel%

pk3cmd -P32MX250f128B -Fa.hex -M -L
if %errorlevel% neq 0 exit /b %errorlevel%

