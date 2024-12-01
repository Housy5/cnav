
Here’s the revised README without the installation section:

cnav - Command Navigator
cnav is a lightweight CLI tool designed to simplify your workflow by aliasing long, complex, and frequently used commands. With cnav, you can easily create, manage, and use command shortcuts, saving you time and effort.

Features
Create Aliases: Replace lengthy commands with simple shortcuts.
View Aliases: Quickly see all your current shortcuts.
Manage Aliases: Remove or clear all aliases as needed.
Easy-to-Use Syntax: Simple commands for everyday convenience.
Usage
Add a Command Alias
bash
Copy code
cnav -add <alias> <command>
Example:

bash
Copy code
cnav -add ll "ls -la"
Use a Command Alias
bash
Copy code
cnav <alias>
Example:

bash
Copy code
cnav ll
List All Aliases
bash
Copy code
cnav -print
Remove an Alias
bash
Copy code
cnav -rem <alias>
Example:

bash
Copy code
cnav -rem ll
Clear All Aliases
bash
Copy code
cnav -clear
Why Choose cnav?
Do you find yourself repeatedly typing out long, tedious commands? cnav is here to streamline your command-line experience. It’s lightweight, efficient, and simple to use, helping you focus on what really matters.

Contributing
We welcome contributions! If you have ideas for improvements or spot any issues, feel free to open an issue or submit a pull request on GitHub.

License
This project is licensed under the MIT License. See the LICENSE file for more details.
