rm -r build/*
mkdir build

# Локальная версия
g++ -I./include -I./src -I./itti_structs -I./itti_structs/asn1c_build -I./rapidjson -o build/main main.cpp src/AdmUeReleaseRequest.cpp src/PathSwitchRequest.cpp src/DrbAdditionalInfo.cpp src/InitialContextSetupAcknowledgement.cpp

# Windows версия
#g++ -I./include -I./src -I./itti_structs -I./itti_structs/asn1c_build -I./rapidjson -o build/main-v2 main-v2.cpp src/AdmUeReleaseRequest.cpp src/PathSwitchRequest.cpp src/DrbAdditionalInfo.cpp src/InitialContextSetupAcknowledgement.cpp

# Linux версия
g++ -I./include -I./src -I./itti_structs -I./itti_structs/asn1c_build -I./rapidjson -o build/main-v3 main-v3.cpp src/AdmUeReleaseRequest.cpp src/PathSwitchRequest.cpp src/DrbAdditionalInfo.cpp src/InitialContextSetupAcknowledgement.cpp

#./build/main
#./build/main-v2
#./build/main-v3