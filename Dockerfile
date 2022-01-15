FROM ubuntu

RUN apt-get -y update
RUN apt-get install -y python3
RUN apt-get install -y python3-pip
RUN pip install python-telegram-bot requests pandas --upgrade

ADD tg_bot.py /
ADD config.py /


CMD ["python3", "./tg_bot.py"]

