from Controller import Controller
class LogInGUI():
	def RequestLogIn():
		contr = Controller
		print("moi ban nhap userName: ")
		userName = input()
		print("moi ban nhap passWord: ")
		passWord = input()
		print(contr.RequestLogIn(userName,passWord))
		return contr.RequestLogIn(userName,passWord)


