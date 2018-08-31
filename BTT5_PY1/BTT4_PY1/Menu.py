from RegisterGUI import RegisterGUI
from LogInGUI import LogInGUI
from Controller import Controller
from LogOutGUI import LogOutGUI
from Model import Model
from BlockFriendGUI import BlockFriendGUI
from DisplayFriendListGUI import DisplayFriendListGUI
from DisplayMessUserSentGUI import DisplayMessUserSentGUI
from DisplayDetailMessGUI import DisplayDetailMessGUI
from SentMessGUI import SentMessGUI
from SeenMess import SeenMess
from ManageFriendsInformationGUI import ManageFriendsInformationGUI
from AddFriendGUI import AddFriendGUI

class Menu(object):
	def Process(self,userID):
		sentMessGUI=SentMessGUI
		logOutGUI = LogOutGUI
		blockFriendGUI=BlockFriendGUI
		displayFriendListGUI=DisplayFriendListGUI
		displayMessUserSentGUI =DisplayMessUserSentGUI 
		displayDetailMessGUI =DisplayDetailMessGUI
		seenMess=SeenMess
		manageFriendsInformationGUI=ManageFriendsInformationGUI
		addFriendGUI =AddFriendGUI 
		print("meo")
		print("your ID: ",userID )
		print("please, choose: ")
		#print("press ctr+B to back view")
		#print("press ctr+N to continue")
		print("0: exit")
		print("1: RequestDislayMesswithFriendGUI")
		print("2: DisplayDetailMessGUI")
		print("3: SentMessGUI")
		print("4: AddFriendGUI")
		print("5: DisplayFriendListGUI")
		print("6: BlockFriendGUI")
		print("7: see seen?")
		print("8: LogOut")
		choose=input()
		if(choose=="0"):
			exit()
		if(choose=="1"):
			displayMessUserSentGUI.RequestDisplayMessUserSentGUI(userID)
		if(choose=="2"):
			displayDetailMessGUI.RequestDisplayDetailMessGUI(userID)
		if(choose=="3"):
			sentMessGUI.RequestSentMess(userID)
		if(choose=="4"):
			addFriendGUI.RequestToAddFriend1(userID)
		if(choose=="5"):
			displayFriendListGUI.RequestToDisplayFriendList(userID)
		if(choose=="6"):
			blockFriendGUI.RequestToBlockFriend(userID)
		if(choose=="7"):
			seenMess.RequestViewMess(userID)
		if(choose=="8"):
			logOutGUI.RequestLogOut(userID)
		return self.Process(userID)
	
	def first(self):
		registerGUI= RegisterGUI
		logInGUI=LogInGUI
		print("press 1 to login, 2 to register")
		choose= input("press:" )
		if(choose=="2"):
			registerGUI.RequestRegister()
			return self.first()
		if(choose=="1"):
		
			userID=logInGUI.RequestLogIn()
			if(userID==None):
				print("no acc, press again!!")
				return self.first()
			if(userID!=None):
				self.Process(userID)
				


