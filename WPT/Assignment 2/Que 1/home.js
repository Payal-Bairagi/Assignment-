
"use strict";

// Display the visitor's welcome message.
function showWelcome() {
    const name = document.getElementById("visitorName").value.trim();
    const message = document.getElementById("welcomeMessage");

    if (name === "") {
        message.innerHTML = "Please enter your name. Welcome!";
    } else {
        message.innerHTML = `Welcome, ${name}!`;
    }
}

// Change between light and dark themes.
let darkMode = false;

function toggleTheme() {
    darkMode = !darkMode;

    if (darkMode) {
        document.body.style.backgroundColor = "#222222";
        document.body.style.color = "#ffffff";
    } else {
        document.body.style.backgroundColor = "#ffffff";
        document.body.style.color = "#222222";
    }

    const button = document.querySelector(
        'button[onclick="toggleTheme()"]'
    );

    button.textContent = darkMode ? "Light mode" : "Dark mode";
}

// Show or hide the skills list.
let skillsVisible = true;

function toggleSkills() {
    const skills = document.getElementById("skillsList");
    const button = document.querySelector(
        'button[onclick="toggleSkills()"]'
    );

    if (skillsVisible) {
        skills.style.display = "none";
        button.textContent = "Show";
    } else {
        skills.style.display = "block";
        button.textContent = "Hide";
    }

    skillsVisible = !skillsVisible;
}

// Load public GitHub repositories.
async function loadRepositories() {
    const repoList = document.getElementById("repoList");
    const message = document.getElementById("repoMessage");

    repoList.innerHTML = "";
    message.style.color = "black";
    message.textContent = "Loading repositories...";

    try {
        // Replace YOUR_GITHUB_USERNAME with your GitHub username.
        const response = await fetch(
            "https://api.github.com/users/YOUR_GITHUB_USERNAME/repos"
        );

        console.log("Response status:", response.status);

        if (!response.ok) {
            throw new Error("Unable to load repositories.");
        }

        const repositories = await response.json();

        repositories.forEach(function(repo) {
            const item = document.createElement("li");
            item.textContent = repo.name;
            repoList.appendChild(item);
        });

        message.textContent = repositories.length === 0
            ? "No public repositories found."
            : `Loaded ${repositories.length} repositories.`;

    } catch (error) {
        message.style.color = "red";
        message.textContent = error.message;
    }
}
