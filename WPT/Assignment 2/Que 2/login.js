
"use strict";

// Shows or hides the password.
function togglePassword() {
    const password = document.getElementById("password");
    const button = document.querySelector(".password-row button");

    if (password.getAttribute("type") === "password") {
        password.setAttribute("type", "text");
        button.textContent = "Hide";
    } else {
        password.setAttribute("type", "password");
        button.textContent = "Show";
    }
}

// Checks the password while the user types.
function checkPassword() {
    const password = document.getElementById("password").value;
    const error = document.getElementById("passwordError");

    const passwordPattern =
        /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[^A-Za-z0-9]).{8,}$/;

    if (password === "") {
        error.textContent = "Password is required.";
    } else if (!passwordPattern.test(password)) {
        error.textContent =
            "Use 8+ characters, uppercase, lowercase, a number and a special character.";
    } else {
        error.textContent = "";
    }
}

// Validates the login form.
function validate() {
    const username = document.getElementById("username").value.trim();
    const usernameError = document.getElementById("usernameError");
    const loginMessage = document.getElementById("loginMessage");

    usernameError.textContent = "";
    loginMessage.textContent = "";

    if (username === "") {
        usernameError.textContent = "Username is required.";
    }

    checkPassword();

    const passwordError =
        document.getElementById("passwordError").textContent;

    if (username === "" || passwordError !== "") {
        return false;
    }

    loginMessage.textContent =
        "Validation successful! This is a demo login.";

    return false;
}
