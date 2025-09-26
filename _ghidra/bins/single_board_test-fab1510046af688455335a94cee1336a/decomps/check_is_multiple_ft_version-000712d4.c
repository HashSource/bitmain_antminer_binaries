
_Bool check_is_multiple_ft_version(char *ft_version)

{
  char *ft_version_local;
  int flag;
  
  return (*ft_version & 0xc0U) == 0xc0;
}

