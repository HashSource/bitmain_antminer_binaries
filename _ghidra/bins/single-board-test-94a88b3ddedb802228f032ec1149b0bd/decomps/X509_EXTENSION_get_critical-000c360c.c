
int X509_EXTENSION_get_critical(X509_EXTENSION *ex)

{
  if (ex != (X509_EXTENSION *)0x0) {
    if (ex->critical < 1) {
      ex = (X509_EXTENSION *)0x0;
    }
    else {
      ex = (X509_EXTENSION *)0x1;
    }
  }
  return (int)ex;
}

