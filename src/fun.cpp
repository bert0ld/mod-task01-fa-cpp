unsigned int faStr1(const char *str) {
    int counter = 0;
    int i = 0;
    bool word = false;
    bool includeNum = false;
    while (str[i] != '\0')
    {
        if((word == false) && (str[i] != ' ')) {
            word = true;
            if((str[i] >= 48) && (str[i] <= 57)) includeNum = true;
        } 
        else if((word == true) && (str[i] != ' ')) {
            if(str[i] >= 48 && str[i] <= 57) includeNum = true;
        } 
        else {
            if((includeNum == false) && (word == true)) counter++;
            word = false;
            includeNum = false;
        }
        i++;
    }
    if(!includeNum && word) counter++;
    return counter;
}
unsigned int faStr2(const char *str) {
	int counter = 0;
    int i = 0;
    bool lower = true;
    bool upper = false;
    bool word = false;
    while(str[i] != '\0') {
        if((word == false) && (str[i] != ' ')) {
            word = true;
            if((str[i] >= 65) && (str[i] <= 90)) upper = true;
        }
        else if((word == true) && (str[i] != ' ')) {
            if((str[i] < 97) || (str[i] > 122)) lower = false;
        }
        else {
            if((upper == true) && (lower == true) && (word == true)) counter++;
            word = false;
            lower = true;
            upper = false;
        }
        i++;
    }
    if((upper == true) && (lower == true) && (word == true)) counter++;
    return counter;
}
unsigned int faStr3(const char *str) {
    int result = 0;
    int i = 0;
    int counter = 0;
    int length = 0;
    double average = 0.0;
    bool word = false;
    while(str[i] != '\0') {
        if((word == false) && (str[i] != ' ')) {
            word = true;
            length++;
            counter++;
        }
        else if ((word == true) && (str[i] != ' ')) length++;
        else {
            word = false;
            average += length;
            length = 0;
        }
        i++;
    }
    if(word == true) average += length;
    average /= counter;
    result = average;
    if(average - result >= 0.5)
       result++;
    return result;
}