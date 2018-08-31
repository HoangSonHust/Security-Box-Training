from Controller import Controller
class ManageFriendsInformationGUI(object):
	def RequestChangeFriendInfo(self):
		controller = Controller
		print("please input friendName:")
		friendName= input()
		print("please input friend Infor: ")
		print("please input Gender: ")
		Gender = input()
		print("please input address: ")
		address = input()
		print("please input DoB: ")
		DoB = input()
		print("you input: %s, %s, %s " % (Gender,address,DoB))
		controller.RequestChangeFriendInfo(controller.TakeUserID(friendName),Gender,address,DoB)


