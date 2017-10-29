#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

ILLEGAL_DATA_STRUCTURES=(" std::list" " <list>" " std::map" " <map>")
VIOLATIONS=()

echo
echo "Detecting coding standards violations:"
for ds in ${ILLEGAL_DATA_STRUCTURES[@]}; do
    printf "    ${YELLOW}${ds}${NC}"
    git grep -q "${ds}"
    result=$?
    
    if [ ${result} == 0 ]; then
        printf " ${RED}[FAIL]${NC}\n"
        VIOLATIONS[${#VIOLATIONS[@]}]=${ds}
    else
        printf " ${GREEN}[OK]${NC}\n"
    fi
done

for violation in ${VIOLATIONS[@]}; do
    echo
    printf "${RED}*** ${ds} usage detected ***${YELLOW}\n"
    printf "    ${ds} violates this project's coding standards.\n"
    printf "    Number of violations found in files:${NC}\n"
    git grep -c "${ds}"
    echo
done

exit ${#VIOLATIONS[@]}
