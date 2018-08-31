from Controller import Controller
from SentMessGUI import SentMessGUI
class SeenMess(object):
	def RequestViewMess(userID):
		controller=Controller
		sentMessGUI=SentMessGUI
		if(controller.TakeFriendThatHaveNotSeenMess(userID)==0):
			print("none mess")
		else:
			print("Here is mumber of mess that you have not seen!! : ")
			print(controller.TakeMessHaveNotSeen(userID))
			print("And these are friend that sent you mess: ")
			for row in controller.TakeFriendThatHaveNotSeenMess(userID):
				print(row)
			print("input friendID to see: ")
			friendID= input()
			for row1 in controller.TakeMessHaveNotSeenMess(userID, friendID):
				print (row1)

			print("if you want to reply, press ctr+R to reply")
			input_key = ord(getch()) 
			if(input_key==18):
				print("input mess: ")
				mess= input()
				controller.RequestSentMess(userID,friendID, mess )
				
			



