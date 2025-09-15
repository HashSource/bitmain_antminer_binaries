
char * SSLeay_version(int type)

{
  char *pcVar1;
  
  if (type == 0) {
    return "OpenSSL 1.0.2c 12 Jun 2015";
  }
  if (type == 3) {
    return "built on: reproducible build, date unspecified";
  }
  if (type == 2) {
    return 
    "compiler: arm-linux-gnueabihf-gcc -I. -I.. -I../include  -DOPENSSL_THREADS -D_REENTRANT -DDSO_DLFCN -DHAVE_DLFCN_H -O3 -Wall"
    ;
  }
  if (type == 4) {
    return "platform: linux-armv4";
  }
  if (type == 5) {
    pcVar1 = "OPENSSLDIR: \"/home/XILINX/bin/ssl\"";
  }
  else {
    pcVar1 = "not available";
  }
  return pcVar1;
}

