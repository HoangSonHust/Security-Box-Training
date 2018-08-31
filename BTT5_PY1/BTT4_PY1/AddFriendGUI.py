from Controller import Controller
class AddFriendGUI(object):
	def RequestToAddFriend1(userID):
		contr = Controller
		print("input friend's userName: ")
		userNameFriend= input()
		print("userNameFriend: ",userNameFriend)
		contr.RequestToAddFriend(userID, contr.TakeUserID(userNameFriend))




