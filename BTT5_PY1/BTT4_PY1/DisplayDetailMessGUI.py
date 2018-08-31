from Controller import Controller
class DisplayDetailMessGUI(object):
	def RequestDisplayDetailMessGUI(userID):
		controller=Controller
		print("input friendName that mess you want to see: ")
		friendName= input()
		#friendID=
		#print(controller.RequestDisplayDetailMess(userID,controller.TakeUserID(friendName)),end = ' ')
		for row in controller.RequestDisplayDetailMess(userID,controller.TakeUserID(friendName)):
			#print (str(row))
			print (str(row))


