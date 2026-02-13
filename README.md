How to Run it !

Follow these steps to get the project running on your machine:
1.Open the Files: Open all the .cpp files in Visual Studio.
2.Build the Solution: Build the project for the Kernel and all the plug-ins (echo, sum, reverse, etc.).
3.Check the Output: Ensure all the generated .exe files and the registry_windows.txt are in the same folder.
4.Run the Kernel: Open your terminal, navigate to the folder, and run:
Kernel-CoreSystem.exe

🛠️ How it Works

1.The Kernel: Greets the user and reads registry_windows.txt.

2.The Registry: A simple text file listing the names of available plug-ins.

3.Dynamic Loading: When you choose an option from the menu, the kernel launches the corresponding .exe file as a separate process.

Want to add a new feature? Just create a new .cpp file, compile it to an .exe, and add its name to the registry file. No need to touch the Kernel code!

