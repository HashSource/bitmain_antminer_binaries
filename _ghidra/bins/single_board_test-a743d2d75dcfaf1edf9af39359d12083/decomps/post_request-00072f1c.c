
char * post_request(char *url,char *post_str)

{
  char *pcVar1;
  char *post_str_local;
  char *url_local;
  
  pcVar1 = strstr(url,"https");
  if (pcVar1 == url) {
    pcVar1 = ssl_request(url,post_str);
  }
  else {
    pcVar1 = http_post(url,post_str);
  }
  return pcVar1;
}

