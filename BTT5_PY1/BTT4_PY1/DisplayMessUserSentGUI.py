from Controller import Controller
class DisplayMessUserSentGUI(object):
	def RequestDisplayMessUserSentGUI(userID):
		controller=Controller
		#controller.RequestDisplayMessUserSentGUI(userID)
		#print(controller.RequestDisplayMessUserSentGUI(userID))
		for row in controller.RequestDisplayMessUserSent(userID):
			print(row[0])


