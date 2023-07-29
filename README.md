# TCP-client-server-implementation

Project: TCP Text File Backup System

Description: Enables reliable text file backup and exchange across networks using TCP.

Language: C Programming and utilizes the socket programming paradigm to establish a connection between the client and server applications.

Client-side: Establishes TCP connection, prompts user to send file.

Server-side: Listens for connections, receives and stores file data, sends confirmation.

Usage: Compile and run the server with specified port. Compile and run the client, connect to server IP and port.

File Structure: client.c and server.c

Working:-
The client-side component of the system is responsible for establishing a TCP connection with the server. Once connected, the client 
prompts the user to send a file. The user can initiate the file transfer using the "send" command.

On the server-side, the application listens for incoming connections from clients. When a connection is established, the server receives the file data sent by the client and saves it as "received_file.txt" on the server's storage.
