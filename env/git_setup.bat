REM Git Setup Script for Windows
REM This script sets up Git for the user.
@echo off

echo Setting up Git...
REM Check if Git is installed
git --version >nul 2>&1
if %errorlevel% neq 0 (
    echo Git is not installed. Please install Git and run this script again.
    exit /b 1
)

REM Prompt the user for their Git username and email
set /p git_username=Enter your Git username:
set /p git_email=Enter your Git email: 

REM Configure Git with the user's information
git config --global user.name "%git_username%"
git config --global user.email "%git_email%"
echo Git configuration has been set up successfully!

REM Show the current Git configuration
echo Current Git configuration:
git config --global --list