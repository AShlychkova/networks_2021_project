## Project description
The project consists of ESP8266 with local http-server that provides information about temperature and humidity and telegram bot for outside access to that information.

### Setup
* **Network setup:** in `control.ino` replace `<name>` and `<password>` with wifi name and password
* ** ESP8266 setup:** compile and write control.ino to ESP8266 with WIFI module. IP address will be written on 115200 serial monitor. To check the rest of the code without ESP8266, run `python3 server.py`
* **Bot setup:** in config.py replace:
1. `<token>` with token from `@BotFather`
2. `<ip>` with ip address from previous step or `127.0.0.1:8080` to run with python server
3. `<username>` with first user of bot
* **Run bot:**
0. install [docker](https://www.docker.com/)
1. run `docker build .`
2. run `docker run -d -v <path-to-data>:/data <image>` where `<path-to-data>` is place to store user_names. If server.py is used add `--net=host` to previous command.

### Bot commands
* `/add_user <username>` - to add new user how will be able to use bot
* `/temperature` - to get temperature
* `/humidity` - to get humidity

