from http.server import BaseHTTPRequestHandler, HTTPServer

hostName = "localhost"
serverPort = 8080

class Server(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text")
        self.end_headers()
        if self.path =='/temperature':
            self.wfile.write(b"0")
        if self.path == '/humidity':
            self.wfile.write(b"50")

if __name__ == "__main__":        
    webServer = HTTPServer((hostName, serverPort), Server)
    webServer.serve_forever()
