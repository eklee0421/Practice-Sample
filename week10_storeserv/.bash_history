./mpclient 127.0.0.1 9190
gcc echo_mpclient.c -o mpclient
./mpclient 127.0.0.1 9190
gcc echo_storeserv.c -o serv
./serv 9190
