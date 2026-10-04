# ================================================
# UDP Client-Server Program (All 4 Functions in ONE program)
# Python 3 - Works on Windows/Linux/Mac
# Features:
#   a. Client-Server Echo
#   b. Arithmetic operations (+, -, *, /) on two integers
#   c. Return ASCII code of a character
#   d. Interactive Chat application
#
# HOW TO RUN:
# 1. Save as udp_server.py and udp_client.py
# 2. First run the server in one terminal:
#    python udp_server.py
# 3. Then run the client in another terminal:
#    python udp_client.py
# 4. Use the menu in the client.
# ================================================

# ==================== udp_server.py ====================
import socket

HOST = '127.0.0.1'   # Localhost (use your PC IP if testing on different machines)
PORT = 9999

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind((HOST, PORT))

print(f"🚀 UDP Server started on {HOST}:{PORT}")
print("Waiting for client requests...\n")

while True:
    data, client_addr = server_socket.recvfrom(1024)
    msg = data.decode('utf-8').strip()
    
    print(f"📥 Received from {client_addr}: {msg}")

    # a. ECHO function
    if msg.startswith("ECHO:"):
        response = msg[5:]                     # Remove prefix and echo back
        server_socket.sendto(response.encode('utf-8'), client_addr)
    
    # b. Arithmetic function
    elif msg.startswith("CALC:"):
        try:
            parts = msg.split(':')
            if len(parts) == 4:
                op = parts[1].strip()
                num1 = int(parts[2])
                num2 = int(parts[3])
                
                if op == '+':
                    result = num1 + num2
                elif op == '-':
                    result = num1 - num2
                elif op == '*':
                    result = num1 * num2
                elif op == '/':
                    if num2 == 0:
                        result = "Error: Division by zero!"
                    else:
                        result = num1 / num2          # float result allowed
                else:
                    result = "Error: Invalid operator! Use +, -, *, /"
                
                server_socket.sendto(str(result).encode('utf-8'), client_addr)
            else:
                server_socket.sendto(b"Error: Wrong CALC format", client_addr)
        except ValueError:
            server_socket.sendto(b"Error: Numbers must be integers", client_addr)
        except Exception as e:
            server_socket.sendto(f"Error: {e}".encode('utf-8'), client_addr)
    
    # c. ASCII function
    elif msg.startswith("ASCII:"):
        char = msg[6:]
        if len(char) >= 1:
            ascii_code = ord(char[0])
            server_socket.sendto(str(ascii_code).encode('utf-8'), client_addr)
        else:
            server_socket.sendto(b"Error: Send one character", client_addr)
    
    # d. Chat function (plain messages = chat)
    else:
        # Treat as chat message
        print(f"💬 Chat from client: {msg}")
        
        if msg.lower() == "exit":
            print("Chat ended by client.")
            continue
        
        reply = input("You (Server) reply (type 'exit' to end chat): ")
        server_socket.sendto(reply.encode('utf-8'), client_addr)
        
        if reply.lower() == "exit":
            print("Chat ended by server.")