#!/bin/bash
# Git Setup Script for Unix/Linux
# This script sets up Git configuration for the user.

# Check if Git is installed
if ! command -v git &> /dev/null
then
    echo "Git is not installed. Please install Git and run this script again."
    exit 1
fi

# Prompt the user for their Git username and email
read -p "Enter your Git username: " git_username
read -p "Enter your Git email: " git_email

# Configure Git with the user's information
git config --global user.name "$git_username"
git config --global user.email "$git_email"
echo "Git configuration has been set up successfully!"

# Show the current Git configuration
echo "Current Git configuration:"
git config --global --list