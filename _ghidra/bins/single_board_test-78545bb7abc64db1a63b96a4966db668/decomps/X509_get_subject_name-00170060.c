
X509_NAME * X509_get_subject_name(X509 *a)

{
  return (X509_NAME *)a->ex_flags;
}

