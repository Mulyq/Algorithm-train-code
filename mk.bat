@echo off
set /p name=
cd code
mkdir "%name%"
copy ..\header.cpp "%name%"\main.cpp
cd "%name%"
.\main.cpp
