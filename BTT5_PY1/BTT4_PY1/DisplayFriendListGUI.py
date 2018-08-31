from Controller import Controller
from msvcrt import getch
class DisplayFriendListGUI(object):
	def RequestToDisplayFriendList(userID):
		controller = Controller
		print("friend list:")
		for row in controller.RequestToDisplayFriendList(userID):
			print (str(row))
		DisplayFriendListGUI.Takelist(userID)
		

	def Takelist(userID):
		controller = Controller
		print("press ctr+D to see defaul list or ctr+C see for city")
		input_key = ord(getch()) 
		if(input_key==4):
			print("defaul list")
			for row in controller.TakeFriendListSentMessToUser(userID):
				print(row)
			DisplayFriendListGUI.Takelist(userID)
		if(input_key==3):
			print("see for city")
			DisplayFriendListGUI.Takelist(userID)
			for row4 in controller.TakeCity(userID):
				print(row4)
			

