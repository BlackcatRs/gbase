char* conversion(InputData user_data) {
  // char buffer[32] = {0};
  char* buffer = (char*) malloc(32 * sizeof(char));

  /*
  signed int :
  0000 0000 0000 0111 = 7

  0000 0000 0000  1 111 = -7
  1111 1111 1111  1 000 = one's complement
  1111 1111 1111  1 001 = two's complement (add one)
  */
  if(user_data.input_base == 10 && user_data.sign)
    sprintf(buffer, "%ld", user_data.input_data);
  else {
    switch(user_data.input_base) {
      case 10:
        sprintf(buffer, "%lu", user_data.input_data);
        break;
      case 16:
        sprintf(buffer, "%lX", user_data.input_data);
        break;
      case 8:
        sprintf(buffer, "%lo", user_data.input_data);
        break;
      case 2:
      {
        int i;
        int pos;
        // eliminate zeros (junks) in front of int
        for(i = 31; i > 0 && !((1<<i) & user_data.input_data); i--);
        // transforming decimal number to binary
        for(pos = 0;i > -1; buffer[pos++] = ((1<<i--) & user_data.input_data) ? '1' : '0');
        buffer[pos] = '\0';
        break;
      }
      default:
        help();
    }
  }
  return buffer;
}
