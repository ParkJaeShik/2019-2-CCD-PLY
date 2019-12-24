
import socket
from threading import Thread


#HOST = '127.0.0.1'
#PORT = 8080
HOST = '13.124.254.143'
PORT = 5555

def rcvMsg(sock):
   while True:
      try:
         data = sock.recv(1024)
         if not data:
            break
         print(data.decode())
      except:
         pass
 
def runChat():
   #tkp.e2.insert(0, "connected")
   with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
      sock.connect((HOST, PORT))
      t = Thread(target=rcvMsg, args=(sock,))
      t.daemon = True
      t.start()
      #msg = input()
      #sock.send(msg.encode())
      while True:
         msg = input()+" "
         if msg == '/quit':
            sock.send(msg.encode())
            break

         sock.send(msg.encode())
print("ID 입력 : ", end='')
runChat()




