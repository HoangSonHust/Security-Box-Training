import sqlite3

class Model(object):
	
	def CreateAccount(userName,passWord,fullName,Gender,address,dateOfBirth):
		lOgInStatus = 1
		Other = 0
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		sql_statement = "INSERT INTO userInfo(userName,fullName, passWord, Gender, address, dateOfBirth,lOgInStatus ,Other) VALUES(?,?,?,?,?,?,?,?);"
		cur.execute(sql_statement, (userName,fullName, passWord, Gender, address, dateOfBirth,lOgInStatus ,Other))
		conn.commit()
		#print("Operation done successfully")
		conn.close()

	def CreateUserTable(userName,passWord):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		#print ("meoooooooooooOpened database successfully");
		cursor = conn.execute("SELECT userID from userInfo where userName=? and passWord=?",(userName, passWord))
		for row in cursor:
			print ("ID = ", row[0])
			strsql = "CREATE TABLE '" + str(row[0]) + "' (`stt`INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, friendID TEXT,friendName TEXT,friendStatus TEXT,TimeAddFriend TEXT)";
			cur.execute(strsql)
			#print ("Operation done successfully");
		conn.close()
		
	def TakeUserID(userName):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("SELECT userID from userInfo where userName= '"+userName+"'")
		for row in cursor:
			return row[0]
	
	def LogOut(userID):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("UPDATE userInfo SET logInStatus = '0'  WHERE userID =?",(str(userID)))
		conn.commit()
		conn.close()

	def TakeUserName(userID):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("SELECT userName from userInfo where userID= '"+str(userID)+"'")
		#rows = cursor.fetchall()
		row = cursor.fetchone()
		if row == None:
			#print("nothing")
			return "NOTHING"
		if row!= None:
			#print(row[0])
			return row[0]

		#for row in cursor:
		#	if row == None:
		#		print("nothing")
		#		return "NOTHING"
		#	if row!= None:
		#		print(row[0])
		#		return row[0]
		

	def AddFriend(userID, friendID,friendName, Time):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		print(userID, friendID,friendName,Time)
		sql_statement ="INSERT INTO '" + str(userID) + "' (friendID, friendName, friendStatus,TimeAddFriend )VALUES(?,?,?,?)"
		cur.execute(sql_statement, (friendID,friendName,1,Time))
		conn.commit()
		conn.close()
		
	def BlockFriend(userID, friendID):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("UPDATE '"+str(userID)+"' SET friendStatus = '0'  WHERE friendID =?",(str(friendID)))
		conn.commit()
		conn.close()

	def TakeFriendList(userID):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("SELECT friendID, friendName from '"+str(userID)+"'")
		rows = cursor.fetchall()
		strColName="ID: Name"
		#print(strColName)
		friendList=list()
		friendList.append(strColName)
		for row in rows:
			strtuple=str(row[0])+ ": "+str(row[1])
			friendList.append(strtuple)
		return friendList

	def TakeMessUserSent(userID):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("SELECT Mess from Messeger where Senter= '"+str(userID)+"'")
		rows = cursor.fetchall()
		strColName="Mess:"
		listMess=list()
		listMess.append(strColName)
		listMess.append(rows)
		#print(rows)
		return rows

	def TakeDetailMessGUI(userID, friendID):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("SELECT messID,TimeReceiverMess,Senter,Receiver,Mess from Messeger where Senter = '" + str(userID) + "'and Receiver= '" + str(friendID) + "' or Senter = '" + str(friendID) + "'and Receiver = '" + str(userID) + "'")
		rows = cursor.fetchall()
		#print(rows)
		detailMessList=list()
		for row in rows:
			strtuple=str(row[0])+ ", "+str(row[1])+ ", "+str(row[2])+ ", "+str(row[3])+ ", "+str(row[4])
			detailMessList.append(strtuple)
		return detailMessList

	def TakeMessIDMax():
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("select max(messID) from Messeger")
		rows = cursor.fetchall()
		for row in rows:
			strMessIDMax=str(row[0])
		#print(int(strMessIDMax))
		return int(strMessIDMax)

	def SentMess(messID,TimeReceiverMess,SecondsMess,Senter,Receiver,Mess,See):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		sql_statement = "INSERT INTO Messeger (messID,TimeReceiverMess,SecondsMess,Senter,Receiver,Mess,See)VALUES(?,?,?,?,?,?,?);"
		cur.execute(sql_statement, (messID,TimeReceiverMess,SecondsMess,Senter,Receiver,Mess,See))
		conn.commit()
		#print("Operation done successfully")
		conn.close()
		
	def CheckHaveMessHaveNotSeen(userID):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		strsql = "select count(See)from Messeger where Receiver = '" + str(userID) + "'";
		cur.execute(strsql)
		rows = cur.fetchall()
		for row in rows:
			CheckHaveMessHaveNotSeen=str(row[0])
		#print(int(CheckHaveMessHaveNotSeen))
		return int(CheckHaveMessHaveNotSeen)

	def TakeFriendThatHaveNotSeenMess(userID):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("select Senter from Messeger where See = '1' and Receiver = '" + str(userID) + "'")
		rows = cursor.fetchall()
		listFriendThatHaveNotSeenMess=list()
		#print(rows)
		for row in rows:
			#print(row[0]+": "+Model.TakeUserName(row[0]))
			strFriendThatHaveNotSeenMess=row[0]+": "+Model.TakeUserName(row[0])
			listFriendThatHaveNotSeenMess.append(strFriendThatHaveNotSeenMess)
		return listFriendThatHaveNotSeenMess

	def TakeMessHaveNotSeenMess(userID, friendID):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("select Mess from Messeger where See = '1' and Senter = '" + str(friendID) + "' and Receiver= '"+str(userID)+"'")
		rows = cursor.fetchall()
		listMessThatHaveNotSeenMess=list()
		#print(rows)
		for row in rows:
			#print(row[0]+": "+Model.TakeUserName(row[0]))
			strMessThatHaveNotSeenMess="__   "+row[0]
			listMessThatHaveNotSeenMess.append(strMessThatHaveNotSeenMess)
		return listMessThatHaveNotSeenMess

	def ChangeMessStatus(userID, friendID):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("UPDATE Messeger SET See = '0'  WHERE See = '1' and Senter ='" + str(friendID) + "' and Receiver ='" + str(userID) + "'")
		conn.commit()
		conn.close()

	def RequestChangeFriendInfo(friendID,Gender,address,DoB):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("UPDATE userInfo SET Gender = '"+Gender+"', address = '"+address+"', dateOfBirth = '"+str(DoB)+"' WHERE userID= '" + str(friendID)+ "'")
		print("UPDATE userInfo SET Gender = '"+Gender+"' and address = '"+address+"' and dateOfBirth = '"+str(DoB)+"' WHERE userID= '" + str(friendID)+ "'")
		conn.commit()
		conn.close()

	def TakeFriendListToSentMess(userID):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("SELECT stt,friendID, friendName from '"+str(userID)+"'")
		rows = cursor.fetchall()
		#strColName="ID: Name"
		#print(strColName)
		friendList=list()
		#friendList.append(strColName)
		for row in rows:
			strtuple=str("stt "+ str(row[0])+ ": "+str(row[2]))
			friendList.append(strtuple)
		return friendList

	def TakeUserIDByPosition(userID, Position):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("SELECT friendID from '"+ str(userID)+ "' where stt= '"+str(Position)+"'")
		for row in cursor:
			#print(row[0])
			return row[0]

	def TakeFriendListSentMessToUser(userID):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("select Senter from Messeger where Receiver ='" + str(userID) + "'")
		rows = cursor.fetchall()
		return rows
	
	def TakeFriendIDList(userID):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("SELECT friendID from '"+str(userID)+"'")
		rows = cursor.fetchall()
		return rows

	def TakeCity(userID):
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("SELECT address from userInfo where userID='"+str(userID)+"'")
		rows = cursor.fetchall()
		return rows


	def TakeUserIDAndUserNamefromCity(userID,city):
		#print(city)
		conn = sqlite3.connect('List.sqlite')
		cur = conn.cursor()
		cursor = conn.execute("SELECT friendID, friendName from '"+str(userID)+"', userInfo where userInfo.address='"+str(city)+"' and userInfo.userID= '"+str(userID)+"'.friendID")
		rows = cursor.fetchall()
		friendList=list()
		#friendList.append(strColName)
		for row in rows:
			strtuple=str(str(row[0])+ ": "+str(row[1]))
			friendList.append(strtuple)
		return friendList