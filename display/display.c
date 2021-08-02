// convert to all bases
void print_buffer(InputData user_data) {
  int bases[] = {10, 16, 8, 2};
  char* bases_names[] = {"Dec", "Hex", "Oct", "Bin"};

  for (size_t i = 0; i < 4; i++) {
    if (user_data.input_base != bases[i])
      user_data.input_base = bases[i];
    printf("%s: %s\n", bases_names[i], conversion(user_data));
  }

}

void help() {
  printf("Usage gbase [OPTIONS]\n");
  printf("\nOptions:\n\n");
  printf("    --help                This help\n");
  printf("    --version             Print version number and exit\n\n");
  printf("    -s                    Treat the number as a signed value\n\n");
  printf("    -d <decimal number>   Print this decimal number in all bases\n");
  printf("    -h <hex number>       Print this hexadecimal number in all \
    bases\n");
  printf("    -o <octal number>     Print this octal number in all bases\n");
  printf("    -b <binary number>    Print this binary number in all bases\n");
}
