# ==================== udp_client.py ====================
import socket

HOST = '127.0.0.1'
PORT = 9999
server_addr = (HOST, PORT)

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

print("🚀 UDP Client started")
print(f"Connected to server at {HOST}:{PORT}\n")

def send_and_receive(message):
    """Helper to send request and get response"""
    client_socket.sendto(message.encode('utf-8'), server_addr)
    data, _ = client_socket.recvfrom(1024)
    return data.decode('utf-8')

while True:
    print("\n" + "="*50)
    print("          UDP CLIENT MENU")
    print("="*50)
    print("1. a. Client-Server Echo program")
    print("2. b. Perform arithmetic on two integers")
    print("3. c. Return ASCII code of a character")
    print("4. d. Client-Server Chat application")
    print("5. Exit")
    print("="*50)
    
    choice = input("\nEnter your choice (1-5): ").strip()
    
    # a. Echo
    if choice == "1":
        print("\n--- ECHO MODE ---")
        message = input("Enter message to send to server: ")
        response = send_and_receive(f"ECHO:{message}")
        print(f"✅ Server echoed back: {response}")
    
    # b. Arithmetic
    elif choice == "2":
        print("\n--- ARITHMETIC MODE ---")
        num1 = input("Enter first integer : ")
        num2 = input("Enter second integer: ")
        op   = input("Enter operator (+ - * /): ").strip()
        
        response = send_and_receive(f"CALC:{op}:{num1}:{num2}")
        print(f"✅ Result from server: {response}")
    
    # c. ASCII
    elif choice == "3":
        print("\n--- ASCII MODE ---")
        char = input("Enter a SINGLE character: ")
        if len(char) == 1:
            response = send_and_receive(f"ASCII:{char}")
            print(f"✅ ASCII code of '{char}' = {response}")
        else:
            print("❌ Please enter only ONE character!")
    
    # d. Chat
    elif choice == "4":
        print("\n--- CHAT MODE (UDP) ---")
        print("Type your messages. Type 'exit' to quit chat.\n")
        
        while True:
            message = input("You (Client): ")
            client_socket.sendto(message.encode('utf-8'), server_addr)
            
            if message.lower() == "exit":
                print("✅ Chat ended by you.")
                break
            
            # Receive server reply
            data, _ = client_socket.recvfrom(1024)
            reply = data.decode('utf-8')
            print(f"Server: {reply}")
            
            if reply.lower() == "exit":
                print("✅ Chat ended by server.")
                break
    
    # Exit
    elif choice == "5":
        print("\n👋 Exiting client. Goodbye!")
        break
    
    else:
        print("❌ Invalid choice! Please enter 1-5.")

# Close socket when client exits
client_socket.close()