from Controller import Controller
class RegisterGUI():
	def RequestRegister():
		contr = Controller
		print("moi ban nhap userName: ")
		userName = input()
		print("moi ban nhap passWord: ")
		passWord = input()
		print("moi ban nhap fullname: ")
		fullname = input()
		print("moi ban nhap Gender: ")
		Gender = input()
		print("moi ban nhap address: ")
		address = input()
		print("moi ban nhap DoB: ")
		DoB = input()
		print("ban da nhap: %s va %s, %s, %s, %s, %s " % (userName,passWord,fullname,Gender,address,DoB))
		contr.CheckRequestRegsiter(userName,passWord,fullname,Gender,address,DoB)
	#RequestRegister()







