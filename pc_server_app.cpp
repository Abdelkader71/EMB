#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <signal.h> 
#include <sys/wait.h> // Include the wait header for waiting on child processes



int main(int argc, char const *argv[])
{
    // Create a server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;

    // Set up the server's address information
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the server socket to the specified address and port
    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    // Start listening for incoming connections
    listen(server_socket, 5);

    std::cout << "Server is listening on port: 8080" << std::endl;

    // Message to be sent to the client
    char buffer[1024] = "Choose Command to be Processed: \n 01- Open Firefox \n 02- Open Terminal \n 03- Open Nautilus \n 04- Open WhatsApp \n 05- Open YouTube \n 06- Open Gmail \n 07- Play Music \n 08- Stop Music \n 09- Open VSCode \n 10- Run Code \n 11- Open embedded course \n";

    // Accept a client connection
    int client = accept(server_socket, NULL, NULL);

    // Number of bytes read from the client
    int bytes = 1;

    // Send the buffer message to the client
    send(client, buffer, sizeof(buffer), 0);

    // Loop to receive and process commands from the client
    while (bytes)
    {
        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Read data from the client into the buffer
        bytes = read(client, buffer, sizeof(buffer));

        // Print the received data
        std::cout << "Received: " << buffer << std::endl;

        // Fork a new process
        pid_t pid = fork();
        if (pid == 0)
        {
            // Execute code based on the received command
            if (strcmp(buffer, "terminal\n") == 0)
            {
                execlp("gnome-terminal", "gnome-terminal", NULL);
            }
            else if (strcmp(buffer, "firefox\n") == 0)
            {
                execlp("firefox", "firefox", NULL);
            }
            else if (strcmp(buffer, "whatsapp\n") == 0)
            {
                execlp("firefox", "firefox", "https://web.whatsapp.com", NULL);
            }
            else if (strcmp(buffer, "youtube\n") == 0)
            {
                execlp("firefox", "firefox", "https://www.youtube.com", NULL);
            }
            else if (strcmp(buffer, "gmail\n") == 0)
            {
                execlp("firefox", "firefox", "https://mail.google.com", NULL);
            }
            else if (strcmp(buffer, "runcode\n") == 0)
            {
                // Replace "your_code_execution_command" with your actual code execution command
                execlp("code", "code", "--goto", "/home/ahmed/work/python_workspace/python_sessions/alexa.py", NULL);
            }
            else if (strcmp(buffer, "playmusic\n") == 0)
            {
                // Play music using mpg123
                execlp("mpg123", "mpg123", "/media/ahmed/New Volume/collection/download/favourit music/New folder/New folder/onlymp3.to - Mega Hits 2023-The Best Of Vocal Deep House Music Mix 2023-Summer Music Mix 2023 (Relax)-utuXaMHrgXM-256k-1657981404827.mp3", NULL);
                    
            }
            else if (strcmp(buffer, "embedded\n") == 0)
            {
                // Open Nautilus and navigate to the specified path
                execlp("nautilus", "nautilus", "/media/ahmed/New Volume/Embedded/Embedded Linux", NULL);
            }



            else
            {
                memset(buffer, 0, sizeof(buffer));
                strcpy(buffer, "Wrong Command");
                std::cout << "Wrong command" << std::endl;
                send(client, buffer, sizeof(buffer), 0);
            }
            exit(0);
        }
    }

    // Check if the client disconnected or an error occurred
    if (bytes == 0)
    {
        std::cout << "Client Disconnected" << std::endl;
    }
    else
    {
        std::cout << "Error!!" << std::endl;
    }

    // Close the server and client sockets
    close(server_socket);
    close(client);

    return 0;
}
