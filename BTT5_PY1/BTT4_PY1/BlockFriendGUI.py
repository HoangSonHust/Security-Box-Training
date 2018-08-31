from Controller import Controller
class BlockFriendGUI(object):
	def RequestToBlockFriend(userID):
		contr = Controller
		print("input friend's userName that you want to block: ")
		userNameFriend= input()
		print("userNameFriend: ",userNameFriend)
		contr.RequestToBlockFriend(userID, contr.TakeUserID(userNameFriend))

