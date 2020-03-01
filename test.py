# import cereal.messaging
from openpilot import msg
import os

if __name__ == '__main__':
    print('a')
# try:
    user_paths = os.environ['PYTHONPATH'].split(os.pathsep) 
    print(user_paths)
