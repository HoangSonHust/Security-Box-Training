from Model import Model
import time
import calendar
import time
class Controller(object):
	
	def CheckRequestRegsiter(userName,passWord,fullname,Gender,address,DoB):
		model = Model
		model.CreateAccount(userName,passWord,fullname,Gender,address,DoB)
		model.CreateUserTable(userName, passWord)

	def RequestLogIn(userName,passWord):
		model = Model
		return model.TakeUserID(userName)

	def RequestLogOut(userID):
		model = Model
		model.LogOut(userID)

	def TakeUserID(userName):
		model = Model
		#print(model.TakeUserID(userName))
		return model.TakeUserID(userName)

	def RequestToAddFriend(userID, friendID):
		model = Model
		ticks = time.time()
		a_timeAsString = time.ctime(ticks)
		model.AddFriend(userID, friendID,model.TakeUserName(friendID) ,a_timeAsString)
		model.AddFriend(friendID,userID ,model.TakeUserName(userID) ,a_timeAsString)
		
	def RequestToBlockFriend(userID, friendID):
		model = Model
		model.BlockFriend(userID, friendID)
		model.BlockFriend(friendID,userID)

	def RequestToDisplayFriendList(userID):
		model = Model
		return model.TakeFriendList(userID)

	def RequestDisplayMessUserSent(userID):
		model = Model
		#print("meo"+model.TakeMessUserSentGUI(userID))
		#print(model.TakeMessUserSentGUI(userID))
		return model.TakeMessUserSent(userID)

	def RequestDisplayDetailMess(userID,friendID):
		model = Model
		return model.TakeDetailMessGUI(userID,friendID)

	def RequestSentMess(userID, friendID, mess):
		model = Model
		MessID= model.TakeMessIDMax()+1
		ticks = time.time()
		TimeReceiverMess= time.ctime(ticks)
		#print(TimeReceiverMess)
		SecondsMess=calendar.timegm(time.strptime(TimeReceiverMess))
		see = 1
		model.SentMess(MessID,TimeReceiverMess,SecondsMess,userID, friendID, mess,see)

			
	def TakeMessHaveNotSeen(userID):
		model = Model
		return model.CheckHaveMessHaveNotSeen(userID)

	def TakeFriendThatHaveNotSeenMess(userID):
		model = Model
		return model.TakeFriendThatHaveNotSeenMess(userID)

	def TakeMessHaveNotSeenMess(userID, friendID):
		model = Model
		model.ChangeMessStatus(userID, friendID)
		return model.TakeMessHaveNotSeenMess(userID, friendID)
	def RequestChangeFriendInfo(friendID,Gender,address,DoB):
		model = Model
		model.RequestChangeFriendInfo(friendID,Gender,address,DoB)

	def TakeFriendListToSentMess(userID):
		model = Model
		return model.TakeFriendListToSentMess(userID)

	def TakeUserIDByPosition(userID, Position):
		model = Model
		return model.TakeUserIDByPosition(userID, Position)

	def TakeFriendListSentMessToUser(userID):
		model = Model
		list1 =model.TakeFriendListSentMessToUser(userID)
		list2 =model.TakeFriendIDList(userID)
		for row1 in list1:
			for row2 in list1:
				if(row1==row2):
					list1.remove(row2)
		for row3 in list1:
			list2.remove(row3)

		list3= list1+list2
		list4= list()
		for row3 in list3:
			strID= str(row3[0])+": "+str(model.TakeUserName(str(row3[0])))
			#print(strID)
			list4.append(strID)
		return list4

	def TakeCity(userID):
		model = Model
		listCity1= list()
		listCity= list()
		for row in model.TakeFriendIDList(userID):
			#print(row[0])
			listCity.append(model.TakeCity(row[0]))
		set1 = set()
		for row1 in listCity:
			set1.add(row1[0])
		result1 = list(set1)
		listCityandID=list()
		for row2 in result1:
			listCityandID.append(row2[0])
			for row3 in model.TakeUserIDAndUserNamefromCity(userID,row2[0]):
				#print(row3)
				listCityandID.append(row3)
		return listCityandID
		