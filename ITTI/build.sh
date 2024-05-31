# Linux версия
rm -r build/*
mkdir build

g++ -I./include -I./src -I./itti_structs -I./itti_structs/asn1c_build -I./rapidjson -o build/Server Server-Linux.cpp src/AdmUeReleaseRequest.cpp src/PathSwitchRequest.cpp src/DrbAdditionalInfo.cpp src/InitialContextSetupAcknowledgement.cpp src/InitialContextSetupResponse.cpp
g++ -I./include -I./src -I./itti_structs -I./itti_structs/asn1c_build -I./rapidjson -o build/Client1 Client1-Linux.cpp src/AdmUeReleaseRequest.cpp src/PathSwitchRequest.cpp src/DrbAdditionalInfo.cpp src/InitialContextSetupAcknowledgement.cpp src/InitialContextSetupResponse.cpp
g++ -I./include -I./src -I./itti_structs -I./itti_structs/asn1c_build -I./rapidjson -o build/Client2 Client2-Linux.cpp src/AdmUeReleaseRequest.cpp src/PathSwitchRequest.cpp src/DrbAdditionalInfo.cpp src/InitialContextSetupAcknowledgement.cpp src/InitialContextSetupResponse.cpp

./build/Server
./build/Client1
./build/Client2
