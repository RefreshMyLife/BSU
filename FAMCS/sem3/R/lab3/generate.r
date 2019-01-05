Sys.setlocale(, "ru_RU")

generate <- function(m, a, c, range, x){
  v = x
  for (i in 1:range) {
    xNext = (a * x + c) %% m 
    v = c(v, xNext)
    x = xNext
  }
  print("�������������� ��������:")
  print(mean(v))
  print("���������:")
  print(m/2)
  
  print("���������:")
  print(var(v))
  
  hist(v, breaks = 16, freq = FALSE, col = "lightblue",
       xlab = "������ ��������",
       ylab = "��������� �����������",
       main = "�����������, ����������� � ������ ���������")
  lines(density(v), col = "red", lwd = 2)
  
  return (v)
}
