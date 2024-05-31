# Linux версия

# Очищаем папку build
rm -r build/*

# Создаем папку build, если при отсутствии
mkdir build

# Создаем поочередно: Server, Client1, Client2.
g++ -I./include -I./src -I./itti_structs -I./itti_structs/asn1c_build -I./rapidjson -o build/Server Server-Linux.cpp src/AdmUeReleaseRequest.cpp src/PathSwitchRequest.cpp src/DrbAdditionalInfo.cpp src/InitialContextSetupAcknowledgement.cpp src/InitialContextSetupResponse.cpp
g++ -I./include -I./src -I./itti_structs -I./itti_structs/asn1c_build -I./rapidjson -o build/Client1 Client1-Linux.cpp src/AdmUeReleaseRequest.cpp src/PathSwitchRequest.cpp src/DrbAdditionalInfo.cpp src/InitialContextSetupAcknowledgement.cpp src/InitialContextSetupResponse.cpp
g++ -I./include -I./src -I./itti_structs -I./itti_structs/asn1c_build -I./rapidjson -o build/Client2 Client2-Linux.cpp src/AdmUeReleaseRequest.cpp src/PathSwitchRequest.cpp src/DrbAdditionalInfo.cpp src/InitialContextSetupAcknowledgement.cpp src/InitialContextSetupResponse.cpp

# Запускаем поочередно: Server, Client1, Client2.
./build/Server
./build/Client1
./build/Client2
