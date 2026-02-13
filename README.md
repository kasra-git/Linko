# Linko - Social Network (Phase 1)

A console-based social network system implemented in **C++** using Object-Oriented Programming principles.

This project is developed for the **Advanced Programming** course (Winter 1404) and focuses on designing the core architecture of a scalable social networking platform.

---

## About The Project

In Phase 1, the goal is to implement the core backend logic using clean OOP design and file persistence — without a graphical interface.

The system allows users to:

- Register and login securely
- Create posts
- Follow other users
- View personalized feeds
- Like and comment on posts
- Save and load data from files

---

## Architecture

The project follows a modular design:

CLI → Controllers → Core System → File Storage

Main components:

- `Network`
- `AuthManager`
- `User`
- `Post`
- `Comment`
- `Feed`
- `CommandLineInterface`

---

## Core Classes

### 🔹 Network
- Stores all users
- Manages global system state
- Handles saving/loading data

### 🔹 User
- Unique username
- Encrypted password
- Display name and bio
- Posts list
- Followers & following lists

### 🔹 Post
- Unique ID
- Content text
- Timestamp
- Like counter
- Comments list

### 🔹 Comment
- Content text
- Author
- Timestamp

### 🔹 Feed
- Collects posts from followed users
- Sorts posts
- Displays formatted output

### 🔹 AuthManager
- User registration
- Username validation
- Secure login handling

### 🔹 CommandLineInterface
- Receives commands
- Calls system logic
- Displays results

---

## Example Commands

- `register <user_name> <password> <display_name> <bio>`
- `login <user_name> <password>`
- `post <post>`
- `feed`
- `follow <user_name>`
- `like <postID>`
- `comment <postID> <comment_text>`
- `save`
- `load`
- `logout`
- `exit`
