
char * SSL_CIPHER_standard_name(int param_1)

{
  if (param_1 != 0) {
    return *(char **)(param_1 + 8);
  }
  return "(NONE)";
}

