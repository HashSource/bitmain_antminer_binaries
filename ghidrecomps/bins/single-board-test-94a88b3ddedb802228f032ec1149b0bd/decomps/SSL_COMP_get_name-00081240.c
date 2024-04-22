
char * SSL_COMP_get_name(COMP_METHOD *comp)

{
  if (comp != (COMP_METHOD *)0x0) {
    comp = (COMP_METHOD *)comp->name;
  }
  return (char *)comp;
}

