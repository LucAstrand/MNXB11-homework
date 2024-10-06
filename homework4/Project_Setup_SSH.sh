#!/bin/bash

# Script to set up a project structure and GitHub repo for the course project.

# Function to handle errors
handle_error() {
    echo "Error: $1"
    exit 1
}

echo "Enter your project name: "
read PROJECT_NAME

# Check if the project name is empty
if [ -z "$PROJECT_NAME" ]; then
    handle_error "Project name cannot be empty."
fi

# Create the project directory structure
mkdir -p "$PROJECT_NAME"/{data,scripts,results} 
echo "Project directory structure created."

# Initialize Git repository and link to GitHub
cd "$PROJECT_NAME" 
git init || handle_error "Failed to initialize Git repository."
echo "Git repository initialized."

# Ask for GitHub repository SSH URL
echo "Enter your GitHub SSH repository URL (remote): "
read GITHUB_URL

# Check if the URL is not empty and is in SSH format
if [ -z "$GITHUB_URL" ] || [[ ! "$GITHUB_URL" =~ ^git@github\.com: ]]; then
    handle_error "Please enter a valid SSH URL format."
fi

# Check for existing remote named origin
if git remote get-url origin &>/dev/null; then
    git remote set-url origin "$GITHUB_URL" || handle_error "Failed to update remote repository."
    echo "Remote GitHub repository updated."
else
    git remote add origin "$GITHUB_URL" || handle_error "Failed to add remote repository."
    echo "Remote GitHub repository added."
fi

# Create a .gitignore file
cat <<EOL > .gitignore 
# Ignore data files
data/*

# Ignore results
results/*

EOL
echo ".gitignore file created."

# Set up the GitHub workflow
echo "Setting up GitHub workflow..."
git add . || handle_error "Failed to stage changes."
git commit -m "Initial project setup with directory structure." || handle_error "Failed to commit changes."
git push -u origin master || handle_error "Failed to push changes to GitHub."
echo "Initial commit pushed to GitHub."

# Optional: Download climate data
echo "Do you want to download example climate data (yes/no)?"
read DOWNLOAD_DATA

if [ "$DOWNLOAD_DATA" = "yes" ]; then
    # Example of downloading a data file (replace with actual link)
    curl -o data/sample_climate_data.csv https://example.com/climate_data.csv || handle_error "Failed to download sample climate data."
    echo "Sample climate data downloaded."
fi

echo "Project setup complete!"
