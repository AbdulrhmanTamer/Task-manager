Task Manager

Overview 🖥️

This project is a Task Manager that allows users to view and manage running processes on their operating system. It retrieves process details such as Process Name, Process ID (PID), and Memory Usage. The project supports sorting processes by name, PID, and memory usage, making it easy to monitor system activity.

Features ✨

🏷️ Retrieve running processes from the OS.

📌 Display process details including Name, PID, and Memory Usage.

🔍 Sort processes by:

Name (Alphabetical Order)

Process ID (Ascending Order)

Memory Usage (Descending Order)

🖥️ Cross-platform support for Windows and Linux.

⚡ Efficient and optimized data retrieval and sorting.

How It Works ⚙️

On Windows, the program fetches running processes using the tasklist command.


The retrieved data is then stored in a Process List Class, which allows sorting and displaying processes efficiently.


Example Output 📋

Processes sorted by Name:
--------------------------------
Name                PID     Memory Usage
chrome.exe         1234    150MB
explorer.exe       5678    50MB
...

Processes sorted by PID:
--------------------------------
Name                PID     Memory Usage
explorer.exe       5678    50MB
chrome.exe         1234    150MB

Contribution 🤝

Contributions are welcome! Feel free to fork the repo, create a new branch, and submit a pull request.

License 📜

This project is open-source under the MIT License.

