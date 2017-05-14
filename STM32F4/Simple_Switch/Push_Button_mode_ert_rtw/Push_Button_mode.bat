cd .

if "%1"=="" (C:\MATLAB\R2015b\bin\win64\gmake -B -f Push_Button_mode.mk all) else (C:\MATLAB\R2015b\bin\win64\gmake -B -f Push_Button_mode.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
